#for each file in dataset
files=CodeJamCrawler/dataset/*
for f in $files
do
  if [ ${f: -4} == ".cpp" ]
  then
    #name=$(cut -d '/' -f3 $f)
    name="${f##*/}"
    name="${name%.*}"
    #echo $f
    #echo $name
    cccc $f 2> /dev/null 1> /dev/null
    python xmlToCsvParser.py < .cccc/cccc.xml > "$name.csv" 
  fi
done
