import sys

class wordCount:
    
    #Private members
    __filename = None
    __words = None
    __word = None
    
    
    
    #constructor
    
    def __init__(self, filename):
        self.__filename = filename
        self.__words=dict()
        
    
    def parseWords(self,line):
        #This function takes string arguement and returns parsed words
        
        wordList = line.lower().split()
        return wordList
        
        
    def __toDict(self,word):

        if word not in self.__words:
            self.__words[word]=1
        else:
            self.__words[word]+=1
    
    def getWordCount(self):

        with open(self.__filename) as f:
            for line in f:
                res = self.parseWords(line)
                for self.__word in res:
                    self.__toDict(self.__word)
        if not bool(self.__words):
            raise Exception("No words found in the txt") 
        
        return self.__words
        
if(__name__=="__main__"):
	#usage
	#python Wordcount.py untitled.txt
	
	
	
	
	a = wordCount(sys.argv[1])
	print(a.getWordCount())

