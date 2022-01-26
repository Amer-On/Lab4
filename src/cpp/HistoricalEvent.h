//
// Created by Amer-On on 21.01.2022.
//
#include <iostream>
#include <string>
#ifndef LAB4_HISTORYDATES_H
#define LAB4_HISTORYDATES_H

#endif //LAB4_HISTORYDATES_H

struct HistoricalEvent {
    int year;
    std::string event;

    HistoricalEvent(int year, std::string event);

    HistoricalEvent();

    char getMostFreqChar();

    void getInfo();
};

void sortByDate(HistoricalEvent* historicalEvent, int size);

void sortByName(HistoricalEvent* historicalEvent, int size);

int countInterval(const HistoricalEvent& firstEvent, const HistoricalEvent& secondEvent);