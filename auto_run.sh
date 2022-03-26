#! /bin/bash

today=`date +%y-%m-%d`
echo "----------------------------------------"
echo $today 
echo "git hub auto updater"
echo "ver 1.0.5"
echo "----------------------------------------"
sleep 1 && clear
git status
echo "----------------------------------------"
echo "업데이트 할 내용을 입력 해주십시오."
echo "----------------------------------------"
read comment
clear
echo "----------------------------------------"
echo "당신이 기재한 내용은 아래와 같습니다."
echo "$today : $comment"
echo "해당 내용으로 깃 커밋을 진행합니까? (1)Yes / (2)no"
echo "----------------------------------------"
read answer
no=2
if [ $answer -eq $no ] ; then
	echo "----------------------------------------"
	echo "github  업로드를 취소합니다."
	echo "프로그램을 종료합니다."
	echo "----------------------------------------"
	exit
fi
echo "----------------------------------------"
echo "git commit 을 진행합니다." 
echo "----------------------------------------"
sleep 1 & clear 
git add .
git commit -m "$today : $comment"
echo "----------------------------------------"
sleep 1 && clear
echo "----------------------------------------"
echo "git push를 진행합니다."
echo "----------------------------------------"
git push -u origin main
sleep 1 && clear
echo "----------------------------------------"

sleep 1 && echo "모든 작업이 마무리 되었습니다."
echo "git 로그를 확인하여 주십시오. "
git log -3