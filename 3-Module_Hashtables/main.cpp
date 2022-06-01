#include"hash.h"
#include<vector>
int main(int argc, char const *argv[])
{
//    hashTable Hashtable;
    std::vector<std::string>
    keys{"lion","tiger","liger","leopard",
         "lemmilion","midoriya","allmight",
         "AllMight","Saiki K","Naruto",
         "Sasuke","Jiraya","Kurama",
         "ErenJeager","Mikasa","Horizon",""};
//    for (const auto& a :keys){
//        std::cout<<a<<"->"<<table.hash(a);
//        std::cout<<std::endl;
//    }

    hashTable mytable{10};
    for(const auto& x:keys){
        mytable.insert(new Node(x));
    }
    mytable.printTable();
//    mytable.printTableSize();
//    Node* temp = mytable.lookup("Mikasa");
    mytable.deleteNode("ErenJeager");
    mytable.deleteNode("Jiraya");
    mytable.deleteNode("AllMight");
    mytable.deleteNode("allmight");
    mytable.printTable();

    return 0;
}
