/*isme we have used istringstream method which can maintain the sentence in the way that
ki ham uss sentence ko break kar sake ek common word me*/


class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
     unordered_set<string> s1(dictionary.begin(), dictionary.end());
    istringstream st(sentence);
    string word;
    string result;
    while(getline(st,word,' ')){  //here we break the sentence in the word by using ' ' space
        string prefix="";
        for(int i=1;i<=word.size();i++){
            prefix=word.substr(0,i);
            if(s1.find(prefix)!=s1.end()){//if we found into the map then we will stop
                break;
            }
        }
        result+=prefix+' ';    //here by using this method we can add the string
    }
    if(!result.empty()){
        result.pop_back();
    }
    return result;
    }
};


//APPROACH 2

ing replaceWords(vector<string>& dictionary, string sentence) {
          unordered_set<string> rootSet(dictionary.begin(), dictionary.end());

    istringstream iss(sentence);
    string word;
    string result;

    while (iss >> word) {  //this method also we can divide into the words
        string prefix;
        for (int i = 1; i <= word.size(); ++i) {
            prefix = word.substr(0, i);
            if (rootSet.find(prefix) != rootSet.end()) {
                break;
            }
        }
        result += prefix + " ";
    }

    if (!result.empty()) {
        result.pop_back();
    }

    return result;
    }