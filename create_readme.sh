rm README.md
echo "##PROJET : Les Aventures de Jena" >> README.md
echo "###![img1] (http://www.hostingpics.net/thumbs/82/06/74/mini_820674spaceship2.png) Contexte" >> README.md
echo "Developpement open-source" >> README.md
echo "Projet libre - Ecole ETNA Alternance, France" >> README.md
echo "***" >> README.md
echo "###![image stats] (http://www.hostingpics.net/thumbs/91/27/86/mini_912786graph26.png) Objectifs" >> README.md
echo "Developpé en C, le projet a vu le jour lors de notre 1ere année en Prep'ETNA." >> README.md
echo "Le but étant de monter en compétence en relevant les défis liés à la création d'un jeu vidéo" >> README.md
echo "(Narration, compétences de développement, utilisation de GitHub...)" >> README.md
echo "***" >> README.md
echo "###![image pc](http://www.hostingpics.net/thumbs/96/92/11/mini_969211webprogramming.png) Développeurs" >> README.md
echo "  Rolland Thomas (ETNA),   " >> README.md
echo "  Bedminster Joseph (ETNA)," >> README.md
echo "***" >> README.md
echo "###![image idee] (http://www.hostingpics.net/thumbs/91/22/54/mini_912254light105.png) Collaborateurs" >> README.md
echo "  Azis Widad (ETNA),   " >> README.md
echo "  Colas Geoffrey (ETNA),   " >> README.md
echo "  Kauch Jonathan (EPITECH),   " >> README.md
echo "  Fraysse Christophe (EPITECH)" >> README.md
echo "***" >> README.md
echo "###INFOS" >> README.md
date >> README.md
echo "   " >> README.md
echo "Nombre de lignes : " >> README.md
cat *.c *.h *.txt | wc -l >> README.md
echo "   " >> README.md
echo "Nombre de caracteres : " >> README.md
cat *.c *.h *.txt | wc -c >> README.md