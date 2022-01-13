#!/bin/bash

version="0.1.0"
author="Zoey"
package_name="$2"  #执行脚本输入的第二个变量
package_dir="$1"

mkdir -p ./$package_dir/DEBIAN     #在deb包目录下再创建DEBIAN目录

#EDF是文件结束标志，整段话意思为将AUTHOR~DATE的字符追加到changelog中
cat <<EDF > ./$package_dir/DEBIAN/changelog
AUTHOR:$author
VERSION:$version
DATE:$(date -R)
EDF



cat <<EDF > ./$package_dir/DEBIAN/copyright
********************************************************************
 * @attention
 *
 * 实验平台：i.Mx6ULL开发板
 * 
 * Zoey个人站点：https://www.kmzerone.com
 *
********************************************************************
EDF



cat <<EDF > ./$package_dir/DEBIAN/control
Source:Zoey_Software
Package:${package_name%.*}
Version:$version
Section:debug
Priority:optional
Architecture:amd64
Maintainer:$author
Description: Build_DEB_Tools
EDF



cat <<EDF > ./$package_dir/DEBIAN/postinst
#!bin/sh
echo "****************************************************************"
echo "welcome to use $package_name!"
echo "****************************************************************"
EDF

sudo chmod 775 ./$package_dir/DEBIAN/postinst

dpkg -b $package_dir $package_name


