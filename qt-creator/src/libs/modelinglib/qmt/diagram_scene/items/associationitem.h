/****************************************************************************
**
** Copyright (C) 2016 Jochen Becher
** Contact: https://www.qt.io/licensing/
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 as published by the Free Software
** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
****************************************************************************/

#ifndef QMT_GRAPHICSASSOCIATIONITEM_H
#define QMT_GRAPHICSASSOCIATIONITEM_H

#include "relationitem.h"

QT_BEGIN_NAMESPACE
class QGraphicsSimpleTextItem;
QT_END_NAMESPACE

namespace qmt {

class DAssociation;
class DAssociationEnd;

class AssociationItem : public RelationItem
{
public:
    AssociationItem(DAssociation *association, DiagramSceneModel *diagramSceneModel,
                    QGraphicsItem *parent = 0);
    ~AssociationItem() override;

protected:
    void update(const Style *style) override;

private:
    void updateEndLabels(const DAssociationEnd &end, const DAssociationEnd &otherEnd,
                         QGraphicsSimpleTextItem **endName,
                         QGraphicsSimpleTextItem **endCardinality, const Style *style);
    void placeEndLabels(const QLineF &lineSegment, QGraphicsItem *endName,
                        QGraphicsItem *endCardinality,
                        QGraphicsItem *endItem, double headLength);

    DAssociation *m_association = 0;
    QGraphicsSimpleTextItem *m_endAName = 0;
    QGraphicsSimpleTextItem *m_endACardinality = 0;
    QGraphicsSimpleTextItem *m_endBName = 0;
    QGraphicsSimpleTextItem *m_endBCardinality = 0;
};

} // namespace qmt

#endif // QMT_GRAPHICSASSOCIATIONITEM_H
