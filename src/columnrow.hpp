#pragma once

struct ColumnRow
{
    int column;
    int row;

    ColumnRow(int column_init, int row_init):
        column(column_init),
        row(row_init) 
        {}
};