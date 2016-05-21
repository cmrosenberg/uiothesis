provider stack {
    probe push(int, unsigned int*);
    probe pop(unsigned int*);
    probe empty(unsigned int);
    probe full(unsigned int*);
};

#pragma D attributes Evolving/Evolving/Common provider stack provider
#pragma D attributes Private/Private/Common provider stack module
#pragma D attributes Private/Private/Common provider stack function
#pragma D attributes Evolving/Evolving/Common provider stack name
#pragma D attributes Evolving/Evolving/Common provider stack args
