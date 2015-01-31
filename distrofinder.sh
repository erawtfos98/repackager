#!/bin/bash

debbased="apt-get"
arch="pacman"
rhbased="yum"

findDistro()
{
	isitdeb=$(whereis -b $debbased  | awk '{print $2}')
	#echo $isitdeb
	isitarch=$(whereis -b $arch | awk '{print $2}')
	#echo $isitarch
	isitrhbased=$(whereis -b $rhbased | awk '{print $2}')
	#echo $isitrhbased

	if [[ ! -z $isitdeb ]] && [[ $isitdeb == "/usr/bin/apt-get" ]]
	then
		echo "deb"
	elif [[ ! -z $isitarch ]] && [[ $isitarch  == "/usr/bin/pacman" ]]
	then
		echo "arch"
	elif [[ ! -z $isitrhbased ]] && [[ $isitrhbased == "/usr/bin/yum" ]]
	then
		echo "yum"
	else
		echo "Unknown Distro"
	fi

	# should there be an option for the user to enter
	# their distro?
}

findDistro
