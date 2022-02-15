modules=("Basics"
        "String_Manipulation"
        "LinkedLists"
        "Hashtables"
        "Stacks"
        "Queues"
        "Recursion"
        "Binary_Search"
        "Trees"
        "Graphs"
        "Final_Project")
rm -rf Module_*
for i in {0..9}
do
    mkdir $i-Module_${modules[$i]};
    cd $i-Module_${modules[$i]};
    echo ${modules[$i]} > temp.txt;
    cd ..
done