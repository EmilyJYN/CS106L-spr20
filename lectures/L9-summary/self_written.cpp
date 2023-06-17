#include <vector>
#include <string>
#include <fstream>
#include <numeric>
#include <iterator>
#include <string>
#include <algorithm>
#include <iostream>
#include <cctype>
#include <cmath>


using std::vector; using std::string; 
using std::cout; using std::endl;
using std::ifstream;

string convertWords(ifstream& filename);
int countWords(const string& str, const string& feature);
vector<int> makeCountVector(const string& filestring);
double get_cos(vector<int>& v1, vector<int>& v2);
vector<int> fileToVec(ifstream& filestream);

const vector<string> FEATURE_VEC{"a", "about", "above", "after", "again", "against", "all", "am", "an", "and",
                                 "any", "are", "aren't", "as", "at", "be", "because", "been", "before", "being",
                                 "below", "between", "both", "but", "by", "can't", "cannot", "could", "couldn't",
                                 "did", "didn't", "do", "does", "doesn't", "doing", "don't", "down", "during",
                                 "each", "few", "for", "from", "further", "had", "hadn't", "has", "hasn't", "have",
                                 "haven't", "having", "he", "he'd", "he'll", "he's", "her","here", "here's", "hers",
                                 "herself", "him", "himself", "his", "how", "how's", "i", "i'd", "i'll", "i'm",
                                 "i've", "if", "in", "into", "is", "isn't", "it", "it's", "its", "itself", "let's",
                                 "me", "more", "most", "mustn't", "my", "myself", "no", "nor", "not", "of", "off",
                                 "on", "once", "only", "or", "other", "ought", "our", "ours", "ourselves", "out",
                                 "over", "own", "same", "shan't", "she", "she'd", "she'll", "she's", "should",
                                 "shouldn't", "so", "some", "such", "than", "that", "that's", "the", "their",
                                 "theirs", "them", "themselves", "then", "there", "there's", "these", "they",
                                 "they'd", "they'll", "they're", "they've", "this", "those", "through", "to", "too",
                                 "under", "until", "up", "very", "was", "wasn't", "we", "we'd", "we'll", "we're",
                                 "we've", "were", "weren't", "what", "what's", "when", "when's", "where", "where's",
                                 "which", "while", "who", "who's", "whom", "why", "why's", "with", "won't", "would",
                                 "wouldn't", "you", "you'd", "you'll", "you're", "you've", "your", "yours",
                                 "yourself", "yourselves", "!", "\"", "#", "$", "%", "&", "'", "(", ")", "*", "+",
                                 ",", "-", ".", "/", ":", ";", "<", "=", ">", "?", "@", "[", "\\", "]", "^", "_",
                                 "`", "{", "|", "}", "~"}; // 用 c string 初始化，转化为了std::string

//conver words in file to countable format
//删除了标点符号和\n，全换成小写
string convertWords(ifstream& filename){
    string ret;
    string line;
    while(std::getline(filename, line)){
        //标点符号前加空格，将所有char换成小写unsigned char。使用unsigned char避免数据类型问题
        string newLine;
        for(char ch : line){
            std::tolower(ch);
            if(std::ispunct(static_cast<unsigned char>(ch))){
                newLine += " ";
            }
            newLine += ch;
        }
        ret += newLine + " "; // \n换成空格
    }
    return ret;
}

//get the word count 
int countWords(const string& str, const string& feature){
    string toFind = " " + feature + " "; //avoid problems like "the" and "there" 
    auto curr = str.begin();
    auto end = str.end();
    int count = 0;
    while(curr!=end){
        auto search_iter = std::search(curr,end,toFind.begin(),toFind.end());
        if(search_iter == end){break;}
        count++;
        curr = search_iter + 1;
    }
    return count;
}

//make word count a vector
vector<int> makeCountVector(const string& filestring){
    vector<int> count_vector;
    for(const string& feature : FEATURE_VEC){
        count_vector.push_back(countWords(filestring, feature));
    }
    return count_vector;
}

//get the cos(theta)
//a.b = cos(theta) * |a| * |b|
double get_cos(vector<int>& v1, vector<int>& v2){
    int inner_prod = std::inner_product(v1.begin(),v1.end(),v2.begin(),0);
    auto mag1 = std::sqrt(std::inner_product(v1.begin(),v1.end(),v1.begin(),0));
    auto mag2 = std::sqrt(std::inner_product(v2.begin(),v2.end(),v2.begin(),0));
    double cos = inner_prod / (mag1 * mag2);
    return cos;
}


//generic function for every file
vector<int> fileToVec(ifstream& filestream){
    string file_str = convertWords(filestream);
    vector<int> word_count_vec = makeCountVector(file_str);
    return word_count_vec;
}

int main(){
    ifstream hamilton_fs("res/hamilton.txt");
    //ifstream jj_fs("res/jj.txt");
    //ifstream gatsby_fs("res/gatsby.txt");
    ifstream unknown_fs("res/unknown.txt");

    //cout << convertWords(hamilton_fs) << endl;
    
    vector<int> vec_unknown = fileToVec(unknown_fs);
    vector<int> vec_hamilton = fileToVec(hamilton_fs);

    cout << "Similarity - hamilton <-> unknown: " << get_cos(vec_hamilton, vec_unknown) << endl;

    return 0;
}