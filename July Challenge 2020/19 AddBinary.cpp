// Algo:
// First reverse both the strings and then add like a normal addition

reverse(a.begin(),a.end());reverse(b.begin(),b.end());
        char carry='0';
//swap if b>a
        if(a.length()<b.length()){string t=a; a=b;b=t;}
        int i;
//now compare bits with smaller array and also check carry
            for(i=0;i<b.length();i++){
                if(b[i]=='1'&&a[i]=='0'&&carry=='0')a[i]='1';
                else if(b[i]=='1'&&a[i]=='1'&&carry=='0'){a[i]='0';carry='1';}
                else if(b[i]=='0'&&a[i]=='0'&&carry=='1'){a[i]='1';carry='0';}
                else if(b[i]=='0'&&a[i]=='1'&&carry=='1'){a[i]='0';}
            }
//now check carry with the remaining bits of the longer array
                 while(carry=='1'&&i<a.length()){
                    if(a[i]=='0'){a[i]='1';carry='0';}
                    else a[i]='0';
                     i++;
                 }
         reverse(a.begin(),a.end());
//if carry is still left
         if(carry=='1')a.insert(a.begin(),carry);
        return a;
