/*#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;
 
int main()
{
	list <int> list1, list2, list3;
	ostream_iterator<int> screen (cout, " ");
	list<int>::iterator it;
	
	cout<<"\t LIST ITERATOR DEMO PROGRAM \n";
	list1.push_back(23);
	list1.push_back(58);
	list1.push_back(58);
	list1.push_back(58);
	list1.push_back(36);
	list1.push_back(15);
	list1.push_back(93);
	list1.push_back(98);
	list1.push_back(58);
	cout<<"\tLIST1\n";
	copy(list1.begin(), list1.end(), screen);
	cout<< endl << "\n";

	list2.push_back(13);
	list2.push_back(23);
	list2.push_back(25);
	list2.push_back(136);
	list2.push_back(198);    
	cout<<"\tLIST2\n";
	copy(list2.begin(), list2.end(), screen);
	cout<< endl << "\n";

	list3.push_back(100);
	list3.push_back(150);
	list3.push_back(200);
	list3.push_back(250);	
	list3.push_back(300);    
	cout<<"\tLIST3\n";
	copy(list3.begin(), list3.end(), screen);
	cout<< endl << "\n";

	list1.sort();
	cout<<"\tLIST1 AFTER SORTING OPERATION\n";
	copy(list1.begin(), list1.end(), screen);
	cout<< endl << "\n";

	list1.unique();
	cout<<"\tLIST1 AFTER UNIQUE OPERATION\n";
	copy(list1.begin(), list1.end(), screen);
	cout<< endl << "\n";

	list1.merge(list3);
	cout<<"\tLIST1 AFTER MERGE OPERATION\n";
	copy(list1.begin(), list1.end(), screen);
	cout<< endl << "\n";

	list1.splice(list1.begin(), list2);
	cout<<"\tLIST1 AFTER SPLICE OPERATION\n";
	copy(list1.begin(), list1.end(), screen);
	cout<< endl << "\n";

	list1.reverse();
	cout<<"\tLIST1 AFTER REVERSE OPERATION\n";
	copy(list1.begin(), list1.end(), screen);
	cout<< endl << "\n";

	list1.remove(100);
	cout<<"\tLIST1 AFTER REMOVE OPERATION\n";
	copy(list1.begin(), list1.end(), screen);
	cout<< endl << "\n";

	it = list1.begin();
	++it; 
	list1.insert(it,2);
	list1.insert(it,2,3);
	cout<<"\tLIST1 AFTER INSERT OPERATION\n";
	copy(list1.begin(), list1.end(), screen);
	cout<< endl << "\n";

	list1.push_front(1);
	cout<<"\tLIST1 AFTER PUSH_FRONT OPERATION\n";
	copy(list1.begin(), list1.end(), screen);
	cout<< endl << "\n";

	list1.pop_back();
	cout<<"\tLIST1 AFTER POP_BACK OPERATION\n";
	copy(list1.begin(), list1.end(), screen);
	cout<< endl << "\n";

	list1.pop_front();
	cout<<"\tLIST1 AFTER POP_FRONT OPERATION\n";
	copy(list1.begin(), list1.end(), screen);
	cout<< endl << "\n";

	cout<<"Reference to the first element in the list1 = " << list1.front()<<endl;
	cout<<"Reference to the last element in the list1 = " << list1.back()<<endl;

	return 0;
}
*/

#include <set>
#include <iostream>
#include <iterator>
#include <algorithm>

struct BrokenOrder 
{
    int order;
    int equality;

    public:
    BrokenOrder(int o, int e) : order(o), equality(e) {}

    bool operator<(const BrokenOrder &rhs) const {
        return order < rhs.order;
    }
    bool operator==(const BrokenOrder &rhs) const {
        return equality == rhs.equality;
    }
};

std::ostream &operator<<(std::ostream &stream, const BrokenOrder &b) {
    return stream << b.equality;
}

// rlbond's magic comparator
struct LessThan : public std::binary_function<BrokenOrder, BrokenOrder, bool> {
    bool operator()(const BrokenOrder& lhs, const BrokenOrder& rhs) const
    {
        return !(lhs == rhs) && (lhs < rhs);
    }
};

int main() {
    std::set<BrokenOrder,LessThan> s;
    for (int i = 0; i < 5; ++i) {
        s.insert(BrokenOrder(i,i));
    }
    for (int i = 0; i < 5; ++i) {
        s.insert(BrokenOrder(10-i,i));
    }
    std::copy(s.begin(), s.end(), 
        std::ostream_iterator<BrokenOrder>(std::cout, "\n"));
	return 0;
}
