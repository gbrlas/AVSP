#for each file in dataset
files=./source_codes/*
for f in $files
do
  #name=$(cut -d '/' -f3 $f)
  name="${f##*/}"
  name="${name%.*}"
  #echo $f
  #echo $name
  ~/Downloads/srcML/bin/srcml $f >> "./processed_asts/$name.srcml"
  python ASTExtractor.py < "./processed_asts/$name.srcml" >> ast_features.csv
done
