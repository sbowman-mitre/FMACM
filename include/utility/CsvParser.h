// ****************************************************************************
// NOTICE
//
// This is the copyright work of The MITRE Corporation, and was produced
// for the U. S. Government under Contract Number DTFAWA-10-C-00080, and
// is subject to Federal Aviation Administration Acquisition Management
// System Clause 3.5-13, Rights In Data-General, Alt. III and Alt. IV
// (Oct. 1996).  No other use other than that granted to the U. S.
// Government, or to those acting on behalf of the U. S. Government,
// under that Clause is authorized without the express written
// permission of The MITRE Corporation. For further information, please
// contact The MITRE Corporation, Contracts Office, 7515 Colshire Drive,
// McLean, VA  22102-7539, (703) 983-6000. 
//
// Copyright 2018 The MITRE Corporation. All Rights Reserved.
// ****************************************************************************

/*
 * Originally from http://stackoverflow.com/questions/1120140/how-can-i-read-and-parse-csv-files-in-c
 *
 * Use in an interator loop, like this:
    std::ifstream       file("testfile.csv");

    for(CSVIterator loop(file);loop != CSVIterator();++loop)
    {
        std::cout << "4th Element(" << (*loop)[3] << ")\n";
    }
 *
 */
#pragma once

#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

namespace CsvParser {

class CsvRow
{
    public:
        std::string const& operator[](std::size_t index) const
        {
            return m_data[index];
        }
        std::size_t size() const
        {
            return m_data.size();
        }
        void readNextRow(std::istream& str)
        {
            std::string         line;
            std::getline(str,line);

            std::stringstream   lineStream(line);
            std::string         cell;

            m_data.clear();
            while(std::getline(lineStream,cell,','))
            {
                m_data.push_back(cell);
            }
        }
    private:
        std::vector<std::string>    m_data;
};

inline std::istream& operator>>(std::istream& str,CsvRow& data)
{
    data.readNextRow(str);
    return str;
}

class CsvIterator
{
    public:
        typedef std::input_iterator_tag     iterator_category;
        typedef CsvRow                      value_type;
        typedef std::size_t                 difference_type;
        typedef CsvRow*                     pointer;
        typedef CsvRow&                     reference;

        CsvIterator(std::istream& str)  :m_str(str.good()?&str:NULL) { ++(*this); }
        CsvIterator()                   :m_str(NULL) {}

        // Pre Increment
        CsvIterator& operator++()               {if (m_str) { (*m_str) >> m_row;m_str = m_str->good()?m_str:NULL;}return *this;}
        // Post increment
        CsvIterator operator++(int)             {CsvIterator    tmp(*this);++(*this);return tmp;}
        CsvRow const& operator*()   const       {return m_row;}
        CsvRow const* operator->()  const       {return &m_row;}

        bool operator==(CsvIterator const& rhs) {return ((this == &rhs) || ((this->m_str == NULL) && (rhs.m_str == NULL)));}
        bool operator!=(CsvIterator const& rhs) {return !((*this) == rhs);}
    private:
        std::istream*       m_str;
        CsvRow              m_row;
};

} // namespace CsvParser

