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
		map<string, int> BidderBid;
		while (getline(input, line)) {
			if (isupper(line[0]) != 1) {
				istringstream bid(line);
				vector<string> temp{ istream_iterator<string>{bid},
					  istream_iterator<string>{} };

				BidderBid.insert(pair<string, int>(temp[0], stoi(temp[1])));
				cout << temp[0] << " " << temp[1] << endl;
			}
			else {
				if (BidderBid.size() != 0) { //sort and write to output

					//mayor valor
					auto max = max_element(BidderBid.begin(), BidderBid.end(),
						[](const pair<string, int>& p1, const pair<string, int>& p2) {
							return p1.second < p2.second; });

					output << max->second << ",";
					//promedio
					output << (accumulate(BidderBid.begin(), BidderBid.end(), 0, [](int acc, std::pair<string, int> p) { return (acc + p.second); })) / BidderBid.size() << ",";

					//menor menor
					auto min = min_element(BidderBid.begin(), BidderBid.end(),
						[](const pair<string, int>& p1, const pair<string, int>& p2) {
							return p1.second < p2.second; });

					output << min->second << endl;

					//write
					/*
					vector<string, int> OrderedOutput;

					copy(BidderBid.begin(), BidderBid.end(), back_inserter<vector<string, int>>(OrderedOutput));

					sort(OrderedOutput.begin(), OrderedOutput.end(),
						[](const pair<string, int>& p1, const pair<string, int>& p2) {
							if (p1.second != p2.second)
								return p1.second < p2.second;
							return p1.first < p2.first;
						});

					for (auto itr = OrderedOutput.begin(); itr != OrderedOutput.end(); ++itr) {
						output << itr[0] <<" "<< itr[1] << '\n';
					}
					*/
					for (auto itr = BidderBid.begin(); itr != BidderBid.end(); ++itr) {
						output << itr->first << " " << itr->second << '\n';
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
		if (BidderBid.size() != 0) { //sort and write to output

					//mayor valor
			auto max = max_element(BidderBid.begin(), BidderBid.end(),
				[](const pair<string, int>& p1, const pair<string, int>& p2) {
					return p1.second < p2.second; });

			output << max->second << ",";
			//promedio
			output << (accumulate(BidderBid.begin(), BidderBid.end(), 0, [](int acc, std::pair<string, int> p) { return (acc + p.second); })) / BidderBid.size() << ",";

			//menor menor
			auto min = min_element(BidderBid.begin(), BidderBid.end(),
				[](const pair<string, int>& p1, const pair<string, int>& p2) {
					return p1.second < p2.second; });

			output << min->second << endl;
			//write
			for (auto itr = BidderBid.begin(); itr != BidderBid.end(); ++itr) {
				output << itr->first << " " << itr->second << '\n';
			}
		}
		input.close();
	}
}
		
	

