git clone "https://github.com/nextjoey/jena.git" JENA
echo "cd JENA\n" >> update.sh
echo "git pull\n" >> update.sh
echo "./jena" >> update.sh
cd JENA
./jena