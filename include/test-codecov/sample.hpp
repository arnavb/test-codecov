#pragma once
#ifndef SAMPLE_HPP_
#define SAMPLE_HPP_

class Test
{
public:
    int headerFunction(int value) const
    {
        if (value == 1)
        {
            return 7;
        }
        else if (value == 2)
        {
            return 8;
        }
        else
        {
            return 9;
        }
    }
    
    int cppFunction(int value) const;
};

#endif // !SAMPLE_HPP_
