files=csvs/*
for f in $files
do
  if [ ${f: -4} == ".csv" ]
  then
    #name=$(cut -d '/' -f3 $f)
    content=$(cat $f)
    echo $f';'$content
    #echo $name
    
  fi
done
