class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0,cmp1,cmp2,j=0;
        if(version1.size() >version2.size()) {
            while(j<version2.size()) {
            cmp1=stoi(version1.substr(i,version1.size()));
            cmp2=stoi(version2.substr(j,version2.size()));
                if(cmp1>cmp2) return 1;
                else if(cmp1<cmp2) return -1;
                while(version1[i]>='0' && version1[i] <='9') i++;
                i++;
                while(j<version2.size() && version2[j]>='0' && version2[j]<='9') j++;
                j++;
                }
            while(i<version1.size()) {
                cmp1=stoi(version1.substr(i,version1.size()));
                if(cmp1!=0) return 1;
                while(i<version1.size() && version1[i]>='0' && version1[i]<='9') i++;
                i++;
            }
            return 0;
        }
        else if(version1.size()==version2.size()) {
            
            while(i<version1.size() || j<version2.size()) {
                if(i<version1.size()) cmp1=stoi(version1.substr(i,version1.size()));
                if(j<version2.size()) cmp2=stoi(version2.substr(j,version2.size()));
                //cout << cmp1 << " " <<cmp2 << endl;
                if(cmp1>cmp2) return 1;
                else if(cmp1<cmp2) return -1;
                while(i<version1.size() && version1[i]>='0' && version1[i]<='9')i++;
                i++;
                while(j<version2.size() && version2[j]>='0' && version2[j]<='9')j++;
                j++;
                //cout << i << " " << j << endl;
            }
            return 0;
        }
        else {
            while(i<version1.size()) {
            cmp1=stoi(version1.substr(i,version1.size()));
            cmp2=stoi(version2.substr(j,version2.size()));
                if(cmp1>cmp2) return 1;
                else if(cmp1<cmp2) return -1;
                while(i<version1.size() && version1[i]>='0' && version1[i] <='9') i++;
                i++;
                while(version2[j]>='0' && version2[j]<='9') j++;
                j++;
                }
            while(j<version2.size()) {
                cmp2=stoi(version2.substr(j,version2.size()));
                if(cmp2!=0) return -1;
                while(j<version2.size() && version2[j]>='0' && version2[j]<='9') j++;
                j++;
            }
            return 0;
            
        }
        return -5;
    }
};