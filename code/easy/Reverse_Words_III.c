void my_strrev(char *s, int n) {
    int i = 0;
    for(i = 0; i < n / 2; ++i) {
        char temp = s[i];
        s[i] = s[n - i - 1];
        s[ n - i - 1] = temp;
    }
}


char* reverseWords(char* s) {
    int n =strlen(s);
    int i = 0;
    int j = 0;
    
    while(i < n) {
        j = i;
        while (j < n && s[j] !=' ') j++;
        my_strrev(&s[i], j - i);
        i = j + 1;
		
    }
    return s;
}