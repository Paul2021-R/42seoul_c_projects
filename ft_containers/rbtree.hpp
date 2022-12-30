#ifndef FT_CONTAINERS_RBTREE_HPP
#define FT_CONTAINERS_RBTREE_HPP

#include "ft_iterator.hpp"
#include <type_traits>

namespace ft {

	enum Color {
		RED, BLACK, NIL
	};

	template<class T>
	class RBNode {

	public:
		typedef T value_type;
		typedef RBNode<T> *node_pointer;

	public:
		value_type data;
		Color color;
		node_pointer parent;
		node_pointer left;
		node_pointer right;

	public:

		RBNode(const value_type &data = value_type(), Color color = RED)
				: data(data), color(color), parent(NULL), left(NULL), right(NULL) {};

		RBNode(const RBNode &other, const value_type &data)
				: data(data), color(other.color), parent(other.parent), left(other.left), right(other.right) {}

		~RBNode() {};

		bool isRoot() { return !parent; };

		bool isLeft() { return parent && parent->left == this; };

		bool isRight() { return parent && parent->right == this; };

		bool isRed() { return color == RED; };

		bool isBlack() { return color == BLACK; };

		bool isNil() { return color == NIL; };

		/**
		 * @brief 루트면 null, 해당 객체가 left 노드이면 부모의 우측 즉 자신의 사촌 노드를 반환한다. 
		 * 
		 * @return node_pointer 
		 */
		node_pointer sibling() {
			if (isRoot()) 
				return NULL;
			if (isLeft()) 
				return parent->right;
			else 
				return parent->left;
		};

		node_pointer uncle() {
			if (isRoot()) 
				return NULL;
			return parent->getSibling();
		};

		node_pointer grandparent() {
			if (isRoot()) 
				return NULL;
			return parent->parent;
		};

	};

	template<class T, class U>
	bool operator<(const ft::RBNode<T> &lhs, const ft::RBNode<U> &rhs) {
		return lhs.data < rhs.data;
	}


	template<class T, class Compare = ft::less<T>, bool isConst = false>
	class rbtree_iterator {
	public:
		typedef T															iterator_type;
		typedef typename iterator_traits<iterator_type>::value_type			value_type;
		typedef typename iterator_traits<iterator_type>::difference_type	difference_type;
		typedef typename iterator_traits<iterator_type>::pointer			pointer;
		typedef typename iterator_traits<iterator_type>::reference			reference;
		typedef typename iterator_traits<iterator_type>::iterator_category	iterator_category;
		typedef RBNode<value_type>*											node_pointer;

	protected:
		node_pointer ptr;
		Compare compare;

	public:
		rbtree_iterator() : ptr(NULL) {}

		rbtree_iterator(node_pointer ptr) : ptr(ptr) {}

		rbtree_iterator(const RBNode<value_type> *ptr) : ptr(const_cast<node_pointer>(ptr)) {}

		template<class U>
		rbtree_iterator(const rbtree_iterator<U, Compare> &other) : ptr(const_cast<node_pointer>(other.base())) {}

		~rbtree_iterator() {}

		reference operator*() { return ptr->data; }

		pointer operator->() { return &ptr->data; }

		reference operator*() const { return ptr->data; }

		pointer operator->() const { return &ptr->data; }

		rbtree_iterator &operator++() {
			if (ptr->right) {
				ptr = ptr->right;
				while (ptr->left)
					ptr = ptr->left;
			} else {
				while (ptr->parent) {
					if (!ptr->isNil() && !compare(ptr->parent->data, ptr->data) && ptr->parent->data != ptr->data) {
						ptr = ptr->parent;
						return (*this);
					}
					ptr = ptr->parent;
				}
			}
			return *this;

		}

		rbtree_iterator operator++(int) {
			rbtree_iterator tmp = *this;
			++*this;
			return tmp;
		}

		rbtree_iterator &operator--() {

			if (ptr->left) {
				ptr = ptr->left;
				while (ptr->right && !ptr->right->isNil())
					ptr = ptr->right;
			} else {

				while (ptr->parent) {

					if (ptr->isNil() || compare(ptr->parent->data, ptr->data)) {
						ptr = ptr->parent;
						return *this;
					}

					ptr = ptr->parent;
				}
			}
			return *this;
		}

		rbtree_iterator operator--(int) {
			rbtree_iterator tmp = *this;
			--*this;
			return tmp;
		}

		template<class U>
		bool operator==(const U &other) { return ptr == other.base(); }

		template<class U>
		bool operator!=(const U &other) { return ptr != other.base(); }

		node_pointer base() { return ptr; }

		node_pointer base() const { return ptr; }

		Compare comparator() { return compare; }
	};

	template<class T, class Compare = ft::less<RBNode<T> >, class Alloc = std::allocator<RBNode<T> > >
	class RBTree {

	public:
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename allocator_type::size_type size_type;
		typedef RBNode<T> node_type;
		typedef node_type *node_pointer;

	private:
		node_pointer _root;
		allocator_type _allocator;
		Compare _comparator;
		node_pointer _end;
		node_pointer _start;

	protected:
		Color getColor(node_pointer node) {
			if (node == NULL) return BLACK;
			return node->color;
		}

		void setColor(node_pointer node, Color color) {
			if (node == NULL) return;
			node->color = color;
		}

		void rotateLeft(node_pointer ptr) {
			node_pointer right_child = ptr->right;
			ptr->right = right_child->left;

			if (ptr->right != NULL)
				ptr->right->parent = ptr;

			right_child->parent = ptr->parent;

			if (ptr->parent == NULL)
				_root = right_child;
			else if (ptr == ptr->parent->left)
				ptr->parent->left = right_child;
			else
				ptr->parent->right = right_child;

			right_child->left = ptr;
			ptr->parent = right_child;
		}

		void rotateRight(node_pointer ptr) {
			node_pointer left_child = ptr->left;
			ptr->left = left_child->right;

			if (ptr->left != NULL)
				ptr->left->parent = ptr;

			left_child->parent = ptr->parent;

			if (ptr->parent == NULL)
				_root = left_child;
			else if (ptr == ptr->parent->left)
				ptr->parent->left = left_child;
			else
				ptr->parent->right = left_child;

			left_child->right = ptr;
			ptr->parent = left_child;
		}

		/**
		 * @brief 제일 작은 노드 값을 발견하기, 왼쪽으로 이동용.
		 * 
		 * @param node 
		 * @return node_pointer 
		 */
		node_pointer minValueNode(node_pointer node) {
			node_pointer ptr = node;
			while (ptr->left != NULL && !ptr->isNil())
				ptr = ptr->left; // 가장 왼쪽 노드를 발견한다. 
			return ptr;
		}

		/**
		 * @brief 가장 큰 노드 값을 발견하기, 오른쪽으로 이동용 
		 * 
		 * @param node 
		 * @return node_pointer 
		 */
		node_pointer maxValueNode(node_pointer node) {
			node_pointer ptr = node;
			while (ptr->right != NULL && !ptr->isNil())
				ptr = ptr->right;
			return ptr;
		}

		size_type getBlackHeight(node_pointer node) {
			size_type height = 0;
			while (node != NULL) {
				if (getColor(node) == BLACK)
					height++;
				node = node->left;
			}
			return height;
		}

		void fixDependencies(node_pointer node) {
			if (node->left)
				node->left->parent = node;
			if (node->right)
				node->right->parent = node;
		}

		node_pointer* selfParentPtr(node_pointer node) {
			if (!node->parent)
				return &_root;
			else if (node->isLeft())
				return &node->parent->left;
			else if (node->isRight())
				return &node->parent->right;
			throw std::exception();
		}
		void swapNode(node_pointer lhs, node_pointer rhs) {
			*selfParentPtr(lhs) = rhs;
			*selfParentPtr(rhs) = lhs;
			std::swap(lhs->parent, rhs->parent);
			std::swap(lhs->left, rhs->left);
			std::swap(lhs->right, rhs->right);
			std::swap(lhs->color, rhs->color);
			fixDependencies(lhs);
			fixDependencies(rhs);
		}
		node_pointer replaceNodeWithLoneChild(node_pointer a, node_pointer b) {
			if (b->parent != a) 
				throw std::exception();
			if (a->left && a->right) 
				throw std::exception();
			if (!a->left && !a->right) 
				throw std::exception();
			b->parent = a->parent;
			*selfParentPtr(a) = b;
			return b;
		}

		void fixInsertRBTree(node_pointer ptr) {
			node_pointer parent = NULL;
			node_pointer grandparent = NULL;
			while (ptr != _root && getColor(ptr) == RED && getColor(ptr->parent) == RED) {
				parent = ptr->parent;
				grandparent = parent->parent;
				if (parent == grandparent->left) { // 조부모 노드 기준 왼쪽에 부모 노드이고, 그 노드의 자식이 ptr 이 된다.
					node_pointer uncle = grandparent->right;
					if (getColor(uncle) == RED) { // 현재 노드가 RED 이고, 법칙을 위해 부모와 삼촌이 모두 BLACK 이 되어야 한다. 할아버지는 RED가 되어야 한다. 
						setColor(uncle, BLACK);
						setColor(parent, BLACK);
						setColor(grandparent, RED);
						ptr = grandparent; // 할아버지가 ptr 의 포인터에 들어간다. 
					} 
					else { // Uncle 이 Black 이고, 따라서 좌회전을 시켜버린다. 
						if (ptr == parent->right) {
							rotateLeft(parent);
							ptr = parent; 
							parent = ptr->parent;
						}
						rotateRight(grandparent);
						std::swap(parent->color, grandparent->color);
						ptr = parent;
					}
				} 
				else { // 부모가 조부모 오른쪽 자식일 때
					node_pointer uncle = grandparent->left;
					if (getColor(uncle) == RED) {
						setColor(uncle, BLACK);
						setColor(parent, BLACK);
						setColor(grandparent, RED);
						ptr = grandparent;
					} 
					else {
						if (ptr == parent->left) {
							rotateRight(parent);
							ptr = parent;
							parent = ptr->parent;
						}
						rotateLeft(grandparent);
						std::swap(parent->color, grandparent->color);
						ptr = parent;
					}
				}
			}
			setColor(_root, BLACK);
		}

		node_pointer insertBST(node_pointer root, node_pointer ptr) {
			if (root == NULL || root->isNil()) // 노드가 없거나, 첫 노드로 끝날 때  
				return ptr;
			if (_comparator(ptr->data, root->data)) { // ptr의 데이터보다 root의 데이터가 크기가 큼 
				root->left = insertBST(root->left, ptr);
				root->left->parent = root;

			}
			else { // 값이 역순으로 큰 경우(ptr이 root 보다 큼)
				root->right = insertBST(root->right, ptr);
				root->right->parent = root;
			}
			return root;
		}

		void fixDeleteRBTree(node_pointer node) {
			if (node->parent) {							// case 1
				if (node->sibling() && node->sibling()->color == RED) 		// case 2
				{
					node->parent->color = RED;
					node->sibling()->color = BLACK;
					if (node->isLeft())
						rotateLeft(node->parent);
					else
						rotateRight(node->parent);
				}
				if (node->parent->color == BLACK && node->sibling() &&		// case 3
					node->sibling()->color == BLACK &&
					(!node->sibling()->left || node->sibling()->left->color == BLACK) &&
					((!node->sibling()->right || node->sibling()->right->isNil()) || node->sibling()->right->color == BLACK))
				{
					node->sibling()->color = RED;
					fixDeleteRBTree(node->parent);
				}
				else if (node->parent->color == RED && node->sibling() &&		// case 4
						 node->sibling()->color == BLACK &&
						 (!node->sibling()->left || node->sibling()->left->color == BLACK) &&
						 ((!node->sibling()->right || node->sibling()->right->isNil()) || node->sibling()->right->color == BLACK))
				{
					node->sibling()->color = RED;
					node->parent->color = BLACK;
				}
				else if (node->isLeft() && node->sibling() &&				// case 5
						 node->sibling()->color == BLACK &&
						 node->sibling()->left && node->sibling()->left->color == RED &&
						 ((!node->sibling()->right || node->sibling()->right->isNil()) || node->sibling()->right->color == BLACK))
				{
					node->sibling()->color = RED;
					node->sibling()->left->color = BLACK;
					rotateRight(node->sibling());
				}
				else if (node->isRight() && node->sibling() &&			// still case 5
						 node->sibling()->color == BLACK &&
						 node->sibling()->right && !node->sibling()->right->isNil() && node->sibling()->right->color == RED &&
						 (!node->sibling()->left || node->sibling()->left->color == BLACK))
				{
					node->sibling()->color = RED;
					node->sibling()->right->color = BLACK;
					rotateLeft(node->sibling());
				}
				if (node->sibling())
					node->sibling()->color = node->parent->color; // case 6
				node->parent->color = BLACK;

				if (node->sibling()) {
					if (node->isLeft()) {
						if (node->sibling()->right && !node->sibling()->right->isNil())
							node->sibling()->right->color = BLACK;
						rotateLeft(node->parent);
					} else {
						if (node->sibling()->right && !node->sibling()->right->isNil())
							node->sibling()->left->color = BLACK;
						rotateRight(node->parent);
					}
				}
			}
		}

		void deleteBST(node_pointer node) {
			if (!node->parent && !node->left && (!node->right || node->right->isNil())) // 부모 노드가 없고, left 가 없고, 우측 노드가 없거나 혹은 우측 노드가 leaf node 인 경우 (root) 케이스
				_root = NULL;
			else if (!node->left && (!node->right || node->right->isNil())) { // left 가 없고, 우측 노드가 없거나 혹은 우측 노드가 leaf node 인 경우 ; 마지막 우측 노드이거나 leaf 노드인 케이스
				if (node->isLeft()) // 그런 node가 왼쪽 노드이며 left 포인터를 지워준다. (부모와 연결 끊기)
					node->parent->left = NULL;
				else // 왼쪽이 아니면 오른쪽 부모의 오른쪽 노드 포인터를 지운다. 
					node->parent->right = NULL;
			} 
			else if (node->left && node->right && !node->right->isNil()) {// 부모 노드이며, 가장 끝 단이 아닌 노드
				node_pointer min = minValueNode(node->right);
				swapNode(node, min); // 현재 지워야 할 가장 작은 값으로 가기 위해서
				deleteBST(node);
			} 
			else if (!node->left) { // left 값이 존재하지 않는 경우, 반대로 가장 작은 값의 분기에 들어섰다. 
				node = replaceNodeWithLoneChild(node, node->right);
				fixDeleteRBTree(node);
			} 
			else if (!node->right || node->right->isNil()) {
				node = replaceNodeWithLoneChild(node, node->left);
				fixDeleteRBTree(node);
			}

		}

		void removalNodeLeftRight(node_pointer node) {
			if (!node) 
				return;
			if (!node->isNil())
			{
				removalNodeLeftRight(node->left);
				removalNodeLeftRight(node->right);
			}
			_allocator.destroy(node);
			_allocator.deallocate(node, 1);
		}

		/**
		 * @brief 노드들 중 가장 왼쪽 start 포인터와 end 포인터를 재 설정 해주는 작업. 
		 * 
		 */
		void fixSEPoints() {
			if (!_root) {
				_start = _root;
				_end = _root;
				return;
			}

			node_pointer current = _root;
			while (current->left != NULL) // 왼쪽 끝까지 간다.
				current = current->left;
			_start = current; // 현재 기준이 되는 첫 시작 지점은 가장 왼쪽 노드이다.

			if (!_end) // end 포인트가 지정되어 있지 않다면, 새롭게 end를 만들고 NIL으로 표시해준다. 
				_allocator.construct(_end, node_type(value_type(), NIL));

			current = _root;
			while (current->right != NULL && !current->right->isNil())
				current = current->right;
			current->right = _end; // 루트 기준 가장 오른쪽에 있는 노드 NULL 혹은 NIL 위치까지 와서, end 노드 포인터를 집어 넣어준다. 
			_end->parent = current; // end 의 노드의 부모에 current 노드 포인터를 대입
		}

	public:
		RBTree(const allocator_type &alloc = allocator_type())
				: _root(NULL), _allocator(alloc), _end(NULL), _start(NULL) {
			_end = _allocator.allocate(1);
			_allocator.construct(_end, node_type(value_type(), NIL)); 
			// 기본 생성시 end 포인터로 집어넣고 duble black 으로 실제 값이 들어가지 않는 leaf node 를 생성한다. 
		}

		~RBTree() {
			if (_end != NULL)
			{
				_allocator.destroy(_end);
				_allocator.deallocate(_end, 1);
			}
		}

		node_pointer insert(const value_type &data) {
			node_pointer node = _allocator.allocate(1);
			_allocator.construct(node, RBNode<value_type>(data)); // 노드 생성
			_root = insertBST(_root, node); // 루트를 기준으로 삽입 위치 판단
			fixInsertRBTree(node); // 노드 밸런싱 진행함
			fixSEPoints(); 

			return node;
		}

		void remove(node_pointer node) {
			if (!node) 
				return;
			deleteBST(node);
			fixSEPoints();
		}

		node_pointer find(const value_type &data) {
			node_pointer current = _root;
			while (current != NULL && !current->isNil()) {
				if (!_comparator(data, current->data) && !_comparator(current->data, data))
					return current;
				else if (_comparator(data, current->data))
					current = current->left;
				else
					current = current->right;
			}
			return _end;
		}

		void clear() {
			removalNodeLeftRight(_root);
			_start = NULL;
			_end = NULL;
		}

		size_type max_size() { return _allocator.max_size(); }

		node_pointer end() { return _end; }

		node_pointer begin() { return _start; }

		node_pointer root() { return _root; }
	};

}

#endif
