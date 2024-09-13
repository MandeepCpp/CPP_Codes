// std::map<T1,T2> m; where T1 is key type and T2 is value type
// std::map is associative container that store elements in key value combination
// where key should be unique , otherwise it overrides the previous value.
// it is implment using self balance binary search tree(AVL/Red Black Tree)
// it store key value pair in sorted order on the basis of key .
//



#include<iostream>
#include<map>
#include<string>
#include<functional>
#include<algorithm>


using namespace std;


int main()
{
    std::map<string,int,std::greater<>> m;
    m["Mandeep"]  = 945;
    m["Nav"]      = 684;
    m.insert(std::make_pair("Naman",458));

    for(const auto& e:m)
    {
        cout<<e.first<<" : "<<e.second<<endl;
    }

    // Example container of pairs
    std::map<int, int> m1 = {{1, 10}, {2, 20}, {3, 30}};

    // Find the maximum element based on the second value in the pair
    auto pr = std::max_element(m1.begin(), m1.end(), [](const std::pair<int, int>& x, const std::pair<int, int>& y) {
        return x.second < y.second; // Compare the second element (value) of the pair
    });

    // Print the key and value of the maximum element
    std::cout << pr->first << " : " << pr->second << std::endl;


    return 0;
}