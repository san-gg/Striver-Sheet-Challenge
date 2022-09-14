bool areAnagram(string &str1, string &str2){
    int arr[26] = {0};
    if(str1.length() <= str2.length()) {
        for(char ch : str1) arr[ch - 'a'] = 1;
        for(char ch : str2) if(arr[ch - 'a'] == 0) return false;
    }
    else {
        for(char ch : str2) arr[ch - 'a'] = 1;
        for(char ch : str1) if(arr[ch - 'a'] == 0) return false;
    }
    return true;
}