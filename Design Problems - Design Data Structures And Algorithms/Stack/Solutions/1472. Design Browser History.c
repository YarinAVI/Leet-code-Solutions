#include<stdlib.h>
#include<string.h>
#include<stdio.h>
typedef struct browser_h {
    int curr;
    int size;
    char ** history;
} BrowserHistory;


BrowserHistory* browserHistoryCreate(char * homepage) {
    BrowserHistory  * obj = (BrowserHistory*)calloc(1,sizeof(BrowserHistory));
    obj->size = 1;
    obj->history = (char**)malloc(obj->size * sizeof(char *));
    obj->history[obj->size-1] = (char*)calloc(strlen(homepage)+1,sizeof(char));
    memcpy(obj->history[obj->size-1],homepage,strlen(homepage)*sizeof(char));
    return obj;
}

void browserHistoryVisit(BrowserHistory* obj, char * url) {
  if(obj->curr == obj->size-1) {
      obj->size++;
      obj->history = (char**)realloc(obj->history,obj->size*sizeof(char*));
      obj->curr++;
      obj->history[obj->curr] = (char *)calloc(strlen(url)+1,sizeof(char));
      memcpy(obj->history[obj->curr],url,strlen(url)*sizeof(char));
  }
    else {
        obj->curr++;
        free(obj->history[obj->curr]);
        obj->history[obj->curr] = (char*)calloc(strlen(url)+1,sizeof(char)); 
        memcpy(obj->history[obj->curr],url,strlen(url)*sizeof(char));
        for(int i=obj->curr+1;i<obj->size;i++) free(obj->history[i]);
        obj->size = obj->curr+1;
        obj->history = (char**)realloc(obj->history,obj->size*sizeof(char*));
    }
}

char * browserHistoryBack(BrowserHistory* obj, int steps) {
    if((obj->curr - steps) <0) {
        obj->curr = 0;
       return obj->history[obj->curr]; 
    } 
    else {
        obj->curr-=steps;
        return obj->history[obj->curr];
    }
}

char * browserHistoryForward(BrowserHistory* obj, int steps) {
  if(obj->curr +steps >=obj->size) {
      obj->curr = obj->size-1;
      return obj->history[obj->curr];
  }
    else {
        obj->curr += steps;
        return obj->history[obj->curr];
    }
}

void browserHistoryFree(BrowserHistory* obj) {
    for(int i=0;i<obj->size;i++) free(obj->history[i]);
    free(obj->history);
    obj->history = NULL;
}
int main() {
BrowserHistory *obj = browserHistoryCreate("leetcode.com");
browserHistoryVisit(obj,"google.com");
browserHistoryVisit(obj,"facebook.com");
browserHistoryVisit(obj,"youtube.com");
printf("%s\n",browserHistoryBack(obj,1));
printf("%s\n",browserHistoryBack(obj,1));
printf("%s\n",browserHistoryForward(obj,1));
browserHistoryVisit(obj,"linkedin.com");
printf("%s\n",browserHistoryForward(obj,2));
printf("%s\n",browserHistoryBack(obj,2));
printf("%s\n",browserHistoryBack(obj,7));
browserHistoryFree(obj);
free(obj);
}