/*
 * This file is part of KDevelop
 *
 * Copyright 2012 Milian Wolff <mail@milianw.de>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Library General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program; if not, write to the
 * Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef TEST_MAKEOUTPUTMODEL_H
#define TEST_MAKEOUTPUTMODEL_H

#include <QObject>

class TestMakeOutputModel : public QObject
{
    Q_OBJECT
public:
    explicit TestMakeOutputModel(QObject* parent = 0);

private slots:
    void benchAddLongLine();
    void benchAddLines();

    void testErrors_data();
    void testErrors();
};

#endif // TEST_MAKEOUTPUTMODEL_H