#include <iostream>
#include <fstream>
#include <iterator>
#include <sstream>
#include <map>
#include <unordered_map>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


int main() {
	ofstream output;
	output.open("result.txt");

	//file input
	string currentuser;
	string line;
	ifstream input("bid_example.txt");
	if (input.is_open()) {
		map<int, string> BidderBid;
		while (getline(input, line)) {
			if (isupper(line[0]) != 1) {
				istringstream bid(line);
				vector<string> temp{ istream_iterator<string>{bid},
					  istream_iterator<string>{} };
				
				BidderBid.insert(pair<int, string>(stoi(temp[1]), temp[0]));
				cout << temp[0]<<" "<< temp[1]<<endl;
			}
			else {
				if (BidderBid.size() != 0) { //sort and write back to file
					//output << accumulate(BidderBid.begin(), BidderBid.end(), 0, [](int acc, std::pair<int, string> p) { return (acc + p.first); }) << endl;

					//sort
					//reverse(BidderBid.begin(), BidderBid.end());
					
					for (auto itr = BidderBid.begin(); itr != BidderBid.end(); ++itr) {
						output << itr->second <<" "<< itr->first << '\n';
					}
					cout << endl;	
				}

				cout << line << "(product name detected)" << endl;
				currentuser = line;
				
				output << currentuser << ",";

				BidderBid.clear();
				currentuser.clear();
			
			}
		}

		input.close();
	}
}
		
	

