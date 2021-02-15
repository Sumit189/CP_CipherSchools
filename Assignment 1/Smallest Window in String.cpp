#include<bits/stdc++.h>
using namespace std;

string find_pattern(string text, string pattern){
	int size1 = text.size();
	int size2 = pattern.size();
	if(size1 < size2){
		cout<<"No window Exists";
		return "";
	}
	int hash_pat[256]={0};
	
	for(int i = 0; i < size2; i++){
		hash_pat[pattern[i]]++;
	}
	
	int hash_string[256]={0};
	
	int min_ = INT_MAX;
	int count = 0, start = 0, start_index=-1;
	for(int i = 0; i < size1; i++){
		hash_string[text[i]]++;
		
		if(hash_string[text[i]] <= hash_pat[text[i]])
		count++;
		
		if(count == size2){
			while(hash_string[text[start]] > hash_pat[text[start]] || hash_pat[text[start]]==0){
				if(hash_string[text[start]] > hash_pat[text[start]])
				hash_string[text[start]]--;
				
				start++;
			}
			
			int len_window = i - start + 1;
            if (min_ > len_window) {
                min_ = len_window;
                start_index = start;
            }
		}
	}
	if(start_index==-1){
		cout<<"No Window Exists";
		return "";
	}
	
	return text.substr(start_index, min_);
}

int main(){
	string text = "this is a computer";
	string pattern = "isisa";
	string res = find_pattern(text,pattern);
	cout<<res;
}
