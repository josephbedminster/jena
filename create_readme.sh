rm README.md
echo "#PROJET --JENA--" >> README.md
echo "###DEVELOPEMENT OPEN SOURCE" >> README.md
echo "ECOLE PREP ETNA ALTERNANCE, FRANCE" >> README.md
echo "###DEVELOPPEURS" >> README.md
echo "  ROLLAND THOMAS (ETNA)" >> README.md
echo "  BEDMINSTER JOSEPH (ETNA)" >> README.md
echo "###COLLABORATEURS" >> README.md
echo "  AZIS WINDA (ETNA)" >> README.md
echo "  COLAS GEOFFREY (ETNA)" >> README.md
echo "  KAUCH JONATHAN (EPITECH)" >> README.md
echo "  FRAYSSE CHRISTOPHE (EPITECH)" >> README.md
echo "###INFOS" >> README.md
date >> README.md
echo " | Nombre de lignes : " >> README.md
cat *.c *.h *.txt | wc -l >> README.md
echo " | Nombre de caracteres : " >> README.md
cat *.c *.h *.txt | wc -c >> README.md