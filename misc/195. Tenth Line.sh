# Read from the file file.txt and output the tenth line to stdout.
num=`wc -l file.txt | awk '{print $1}'`
if [ $num -ge 10 ]; then
    head -10 file.txt | tail -1
fi