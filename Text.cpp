#include "stdafx.h"
#include "Text.h"


Text::Text(QGraphicsScene *scene, MyPlane *player) :scene(scene), player(player)

{
}

Text::~Text()
{

}
void Text::timerEvent(QTimerEvent *event)
{
}

QRectF Text::boundingRect()const
{
	return QRectF(-10, -10, 200, 50);

}
void Text::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	QFont font("����", 15, QFont::Bold, true);
	painter->setFont(font);

	painter->setPen(Qt::red);
	QString s1 = QString::number(player->getIntegral(), 10);
	painter->drawText(10, 20, QStringLiteral("������") + s1);
	QString s2 = QString::number(player->getBlood(), 10);
	painter->drawText(10, 45, QStringLiteral("����ֵ��") + s2);
	if (player->isInvincible())
		painter->drawText(10, 70, QStringLiteral("�޵У���"));
	else
		painter->drawText(10, 70, QStringLiteral("�޵У���"));
	update();
}
