project(spade)

set(CMAKE_CXX_STANDARD 14)

add_executable(spade src/main.cpp src/Spade.cpp src/Spade.h src/EquivalenceClass.cpp src/EquivalenceClass.h src/SequenceDatabase.cpp src/SequenceDatabase.h src/Pattern.cpp src/Pattern.h src/FrequentPatternEnumeration.cpp src/FrequentPatternEnumeration.h src/CandidateGenerator.cpp src/CandidateGenerator.h)