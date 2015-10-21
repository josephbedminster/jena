rm README.md
echo "#PROJET: Les Aventures de Jena" >> README.md
echo "###Developpement open-source" >> README.md
echo "Projet libre - Ecole ETNA ALternance, France" >> README.md
echo "---" >> README.md
echo "###Developpeurs" >> README.md
echo "  Rolland Thomas (ETNA)," >> README.md
echo "  Bedminster Joseph (ETNA), " >> README.md
echo "---" >> README.md
echo "###Collaborateurs" >> README.md
echo "  Azis Winda (ETNA), " >> README.md
echo "  Colas Geoffrey (ETNA), " >> README.md
echo "  Kauch Jonathan (EPITECH), " >> README.md
echo "  Fraysse Christophe (EPITECH)" >> README.md
echo "---" >> README.md
echo "###INFOS" >> README.md
date >> README.md
echo " | Nombre de lignes : " >> README.md
cat *.c *.h *.txt | wc -l >> README.md
echo " | Nombre de caracteres : " >> README.md
cat *.c *.h *.txt | wc -c >> README.md