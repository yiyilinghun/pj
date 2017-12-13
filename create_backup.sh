#! /bin/bash

packetname=$(basename $(pwd))

echo -e "\033[31m 正在对git版本库打包...\033[0m"
tar -cf ./$packetname.tar .git/

#echo -e "\033[34m 正在备份git版本库到E盘根目录...\033[0m"
#cp /d/$packetname.tar /e/

#echo -e "\033[34m 正在备份git版本库到F盘根目录...\033[0m"
#cp /d/$packetname.tar /f/

for arg in "$@"
do
	mkdir -p $arg
	if [ -d $arg ] 
	then
		cp ./$packetname.tar $arg
		echo -e "\033[34m 正在备份git版本库到$arg盘根目录...\033[0m"
	else 
		echo -e "\033[31m $arg不是一个合法的路径\033[0m"

	fi
done

if [ $# -gt 0 ] 
then
	rm ./$packetname.tar
fi

echo -e "\033[32m 备份完成...\033[0m"

