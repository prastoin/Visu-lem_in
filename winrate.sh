#!/usr/bin/env bash
clear
echo "" > result
cpt=0
O=0
name=0
m=0
game=0
echo "Choissez votre carte entre 0 et 2."
read m
if [ $m != 0 ] && [ $m != 1 ] && [ $m != 2 ]
then
	echo "Mau:w
	vaise map, error."
	exit
fi
echo "Rentrez le numero de joueur de prastoin."
read O
if [ $O != 1 ] && [ $O != 2 ]
then
	echo "Mauvais numero de Joueur, error."
	exit
fi
echo "Rentrez le nom de l'adversaire (<name>.filler)."
read name
if [ $name != "abanlin" ] && [ $name != "carli" ] && [ $name != "champely" ] \
	&& [ $name != "grati" ] && [ $name != "hcao" ]&& [ $name != "superjeannot" ]
then
	echo "Mauvais nom de joueur, error."
	exit
fi
if [ $name != "abanlin" ] && [ $name != "carli" ] && [ $name != "champely" ]
then
	game=25
fi
if [ $name != "grati" ] && [ $name != "hcao" ]&& [ $name != "superjeannot" ]
then
	game=100
fi
game=$((($game/($m+1))/($m+1)))
X=$((2-($O + 1)%2))
while ((cpt!=game))
do
	clear
	echo "$((($cpt*100)/$game))%"
	~/resources/./filler_vm -f ~/resources/maps/map0$m -p$O ./prastoin.filler \
		-p$X ~/resources/./players/$name.filler | ./data
	((cpt+=1))
done
clear
echo "Prastoin en p$O vs $name en p$X"
./score $O
rm -rf filler.trace
