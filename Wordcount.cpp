#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;




class wordCount{
    
    //Private members
    
    private:
    
    
    	string filename;
    	unordered_map<string, int> words;
    	string word;
    	fstream file;
    
    	
    	
    	void toDict(string word){
    		if(words.find(word) != words.end()){
    		
    			words.at(word)++;
    			
    		}else{
    		
    			words.insert({word, 1});
    		
    		}
    	}
    	
    //public members
    	
    public:
    
    	wordCount(string s){                                               //constructor
    		filename = s;
    		
    		//return getWordCount();
    	}  
    	
    	//function for parsing
    	vector<string> parseWords(string input_string); 

    	//function for accumulating parsed words into a map
	unordered_map<string, int> getWordCount(){
	
		file.open(filename,ios::in);
		vector<string>::iterator ptr;
		
		try{
		
			if (file.is_open()){   			//To ensure file is open
			
				string str1;
				
				while(getline(file, str1)){
					if (str1.empty()){continue;}
					vector<string> vec1 = parseWords(str1);
					
								//for (ptr = vec1.begin(); ptr<vec1.end(); ptr++){
					for(auto ptr = vec1.cbegin(); ptr != vec1.cend(); ++ptr){
						toDict(*ptr);
					
					}
				}
				
						
			}else {
				throw 404;   						//Any error number
			}
		}catch (int num){
			cout<<"File not found.\n";
			cout << "Error number: " << num;
			
		}
	
     	return words;
     	}
};
    
    
vector<string> wordCount::parseWords(string input_string) {
	
	//string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
	//	return x == y and x == ' ';
	//});
	
	auto new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
		return x == y and x == ' ';
	});

	input_string.erase(new_end, input_string.end());

	while (input_string[input_string.length() - 1] == ' ') {
	input_string.pop_back();
    	}

    	vector<string> splits;
    	auto delimiter = ' ';
	
    	string sl;
    
    	size_t i = 0;
    	size_t pos = input_string.find(delimiter);

    	while (pos != string::npos) {
		sl = input_string.substr(i, pos - i);
        	transform(sl.begin(), sl.end(), sl.begin(), ::tolower);
        	splits.push_back(sl);

        	i = pos + 1;
        	pos = input_string.find(delimiter, i);
    	}
    
    
    	sl = input_string.substr(i, min(pos, input_string.length()) - i + 1);
    	transform(sl.begin(), sl.end(), sl.begin(), ::tolower);
    

    
	
    	splits.push_back(sl);
    
    	return splits;
}
  
 
 
  
    
template<typename K, typename V>
void print_map(std::unordered_map<K,V> const &m)
{
    for (auto it = m.cbegin(); it != m.cend(); ++it) {
        std::cout << "{" << (*it).first << ": " << (*it).second << "}\n";
    }
}
    
    
int main(int argc, char** argv) 
{ 

    //Usage
    //g++ Wordcount.cpp -o out
    //./output filename.txt
    
    cout << "The words with their frequencies are :\n"<<endl;
    
    wordCount obj(argv[1]);
    //unordered_map<string, int> words = obj.getWordCount();
    auto words = obj.getWordCount();
    
    if(words.empty()){
    	cout<<"No words found";
    }else{
    	print_map(words);
    }
  
    return 0; 
} 
