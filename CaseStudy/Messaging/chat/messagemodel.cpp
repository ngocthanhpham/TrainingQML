#include "messagemodel.h"
#include <QDateTime>
#include "broadcast/message.h"
#include <QDebug>

MessageModel::MessageModel()
{
    m_nameRoles[COL_NAME] = "name";
    m_nameRoles[COL_OWNER] = "owner";
    m_nameRoles[COL_CONTENT] = "content";
    m_nameRoles[COL_TIMESTAMP] = "timestamp";

//    mMessagePtr = std::shared_ptr<Message>(new Message);

//    Message* mes1 = new Message();

////    mes1->setId(1);
//    mes1->setName("A");
//    mes1->setOwner("Me");
//    mes1->setContent("He he");
//    mes1->setTimestamp(QDateTime::currentDateTime().toString());

//    Message* mes2 = new Message();
////    mes2->setId(2);
//    mes2->setName("B");
//    mes2->setOwner("Me");
//    mes2->setContent("He he");

//    Message* mes3 = new Message();
////    mes3->setId(3);
//    mes3->setName("C");
//    mes3->setOwner("Other");
//    mes3->setContent("He he");

//    Message* mes4 = new Message();
////    mes4->setId(4);
//    mes4->setName("D");
//    mes4->setOwner("Me");
//    mes4->setContent("He he");

//    Message* mes5 = new Message();
////    mes5->setId(5);
//    mes5->setName("E");
//    mes5->setOwner("Me");
//    mes5->setContent("He he");

//    mListMessage.push_back(mes1);
//    mListMessage.push_back(mes2);
//    mListMessage.push_back(mes3);
//    mListMessage.push_back(mes4);
//    mListMessage.push_back(mes5);
}

int MessageModel::rowCount(const QModelIndex &parent) const
{
    return mListMessage.count();
}

int MessageModel::columnCount(const QModelIndex &parent) const
{
    return m_nameRoles.count();
}

QVariant MessageModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
        if(row < 0 || row >= mListMessage.count()) {
            return QVariant();
        }
        Message* var = mListMessage.at(row);
        switch(role) {
        case COL_NAME:
            // return the color name as hex string (model.name)
            return var->name();
        case COL_OWNER:
            // return the hue of the color (model.hue)
            return var->owner();
        case COL_CONTENT:
            // return the saturation of the color (model.saturation)
            return var->content();
        case COL_TIMESTAMP:
            // return the brightness of the color (model.brightness)
            return var->timestamp();
        }
        return QVariant();
}

QVariant MessageModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    return QVariant();
}

QHash<int, QByteArray> MessageModel::roleNames() const
{
    return m_nameRoles;
}

void MessageModel::updateMessage(const Message &data)
{
    qDebug() << "MessageModel::updateMessage update message";
    beginInsertRows(QModelIndex(),0,0);
    Message* mes = new Message;
    mes->setName(data.name());
    mes->setOwner(data.owner());
    mes->setContent(data.content());
    mes->setTimestamp(data.timestamp());
    mListMessage.insert(0,mes);
    endInsertRows();
    emit layoutChanged();
}
