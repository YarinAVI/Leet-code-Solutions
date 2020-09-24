typedef struct trie_node {
    struct trie_node *sub_chars[26];
    bool EOW;
} WordDictionary;

/** Initialize your data structure here. */

WordDictionary* wordDictionaryCreate() {
    WordDictionary *obj = (WordDictionary*)calloc(1,sizeof(WordDictionary));
    return obj;
}

/** Adds a word into the data structure. */
void wordDictionaryAddWord(WordDictionary* obj, char * word) {
  while((*word)) {
      if(obj->sub_chars[(*word)-'a']==NULL) {
          obj->sub_chars[(*word)-'a'] = (WordDictionary*)calloc(1,sizeof(WordDictionary));
      }
      obj = obj->sub_chars[(*word)-'a'];
      word++;
  }
    obj->EOW = true;
}

/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
bool wordDictionarySearch(WordDictionary* obj, char * word) {
    while(*word) {
        if( (*word) =='.') {
            for(int i =0;i<26;i++) {
                if(!obj->sub_chars[i]) continue;
                bool a = wordDictionarySearch(obj->sub_chars[i],word+1);
                if(a) return true;
            }
            return false;
        }
        else if(!obj->sub_chars[(*word)-'a']) return false;
        obj = obj->sub_chars[(*word)-'a'];
        word++;
    }
    if(obj->EOW)return true;
    else return false;
}

void wordDictionaryFree(WordDictionary* obj) {
    //recursivly free the memory
    for(int i=0;i<26;i++) {
        if(!obj->sub_chars[i]) continue;
        wordDictionaryFree(obj->sub_chars[i]);
    }
    free(obj);
}

/**
 * Your WordDictionary struct will be instantiated and called as such:
 * WordDictionary* obj = wordDictionaryCreate();
 * wordDictionaryAddWord(obj, word);
 
 * bool param_2 = wordDictionarySearch(obj, word);
 
 * wordDictionaryFree(obj);
*/