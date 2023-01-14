class Solution {
public:
    int str_val(char a)
{
        int count=0;
		if(a=='I'){
            count= 1;
        }
        else if(a=='V'){
            count= 5;
        }
        else if(a=='X'){
            count= 10;
        }
        else if(a=='L'){
            count= 50;
        }
        else if(a=='C'){
            count= 100;
        }
        else if(a=='D'){
            count= 500;
        }
    	else if(a=='M'){
            count= 1000;
        }
        return count;
}

int romanToInt(string s) {
	int sum=0;
for (int i=0;s[i]!='\0';i++){
    if((str_val(s[i])<str_val(s[i+1]))&&s[i+1]!='\0'){
        sum=sum-str_val(s[i]);
	}
	else if(s[i]=='I'){
        sum+=1;
    }
    else if(s[i]=='V'){
        sum+=5;
    }
    else if(s[i]=='X'){
        sum+=10;
    }
    else if(s[i]=='L'){
        sum+=50;
    }
    else if(s[i]=='C'){
        sum+=100;
    }
    else if(s[i]=='D'){
        sum+=500;
    }
    else if(s[i]=='M'){
        sum+=1000;
    }
}
    return sum;
}
};
