vector<string> helloWorld(int N) {
    // Write your code here.
    vector<string>ans;
    for(int i=1;i<=N;i++){
        if(i%3==0 && i%5==0){
            ans.push_back("HelloWorld");
        }
        else if(i%3==0 && i%5!=0){
            ans.push_back("Hello");
        }
        else if(i%3!=0 && i%5==0){
            ans.push_back("World");
        }
        else{
            ans.push_back(to_string(i));
        }
    }

    return ans;

}
