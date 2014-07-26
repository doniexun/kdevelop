#!/usr/bin/python3
# -*- coding: utf-8 -*-
# This file is part of qmljs, the QML/JS language support plugin for KDevelop
# Copyright (c) 2014 Denis Steckelmacher <steckdenis@yahoo.fr>
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License as
# published by the Free Software Foundation; either version 2 of
# the License or (at your option) version 3 or any later version
# accepted by the membership of KDE e.V. (or its successor approved
# by the membership of KDE e.V.), which shall act as a proxy
# defined in Section 14 of version 3 of the license.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

import sys
sys.path.append('../qmlplugins')

from jsgenerator import *
from common import *

# Print the license of the generated file (the same as the one of this file)
license()
basicTypes(globals())
require('event')

_function = 'function(){}'
_object = 'new Object()'

Module().members(
    F('new Domain()', 'create'),
    Class('Domain').prototype('event.EventEmitter').members(
        F(_void, 'run', ('fn', _function)),
        Var(_array, 'members'),
        F(_void, 'add', ('emitter', _object)),
        F(_void, 'remove', ('emitter', _object)),
        F(_function, 'bind', ('callback', _function)),
        F(_function, 'intercept', ('callback', _function)),
        F(_void, 'enter'),
        F(_void, 'exit'),
        F(_void, 'dispose')
    )
).print()
