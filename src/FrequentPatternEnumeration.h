#ifndef SPADE_FREQUENTPATTERNENUMERATION_H
#define SPADE_FREQUENTPATTERNENUMERATION_H

#include "CandidateGenerator.h"

class FrequentPatternEnumeration {
    CandidateGenerator *candidateGenerator;
    double minSupport;
    int frequentPatterns = 0;

public:
    FrequentPatternEnumeration(CandidateGenerator *candidateGenerator, double minSupport) : candidateGenerator(
            candidateGenerator), minSupport(minSupport) {}

    void setFrequentPatterns(int frequentPatternCount) {
        frequentPatterns = frequentPatternCount;
    }

    int getFrequentPatterns() {
        return frequentPatterns;
    }

    void execute() {};
};


#endif //SPADE_FREQUENTPATTERNENUMERATION_H
