#! /bin/bash

packetname=$(basename $(pwd))

echo -e "\033[31m 正在对git版本库打包...\033[0m"
tar -zcvf ./$packetname.tar.gz .git/

#echo -e "\033[34m 正在备份git版本库到E盘根目录...\033[0m"
#cp /d/$packetname.tar /e/

#echo -e "\033[34m 正在备份git版本库到F盘根目录...\033[0m"
#cp /d/$packetname.tar /f/

for arg in "$@"
do
	mkdir -p $arg
	if [ -d $arg ] 
	then
		cp ./$packetname.tar.gz $arg
		echo -e "\033[34m 正在备份git版本库到$arg盘根目录...\033[0m"
	else 
		echo -e "\033[31m $arg不是一个合法的路径\033[0m"

	fi
done

if [ $# -gt 0 ] 
then
	rm ./$packetname.tar.gz
fi

echo -e "\033[32m 正在推送到github...\033[0m"
git push origin master

echo -e "\033[32m 备份完成...\033[0m"

