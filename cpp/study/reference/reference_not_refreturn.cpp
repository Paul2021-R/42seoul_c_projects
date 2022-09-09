int function(){
	int a = 5;
	return a;
}

int main(){
	int& c = function();
	return (0);
}
