rm README.md
echo "#\nPROJET --JENA--\n" >> README.md
echo "##DEVELOPEMENT OPEN SOURCE" >> README.md
echo "ECOLE PREP ETNA ALTERNANCE, FRANCE\n" >> README.md
echo "###DEVELOPEURS :" >> README.md
echo "- ROLLAND THOMAS (ETNA)" >> README.md
echo "- BEDMINSTER JOSEPH (ETNA)\n" >> README.md
echo "###COLLABORATEURS :\n" >> README.md
echo "- AZIS WINDA (ETNA)" >> README.md
echo "- COLAS GEOFFREY (ETNA)" >> README.md
echo "- KAUCH JONATHAN (EPITECH)" >> README.md
echo "- FRAYS CHRISTOPHE (EPITECH)\n" >> README.md
echo "=============================" >> README.md
date >> README.md
echo "=============================" >> README.md
echo "Nombre de lignes : " >> README.md
cat *.c *.h *.txt | wc -l >> README.md
echo "Nombre de caracteres : " >> README.md
cat *.c *.h *.txt | wc -c >> README.md
echo "\n" >> README.md
clear