#ifndef MESSAGEMODEL_H
#define MESSAGEMODEL_H

#include <QAbstractTableModel>
#include <memory>

class Message;

class MessageModel : public QAbstractTableModel
{
    enum TBL_MSG_COL
    {
        COL_NAME = Qt::UserRole + 1,
        COL_OWNER,
        COL_CONTENT,
        COL_TIMESTAMP,

    };
public:
    MessageModel();

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    QHash<int, QByteArray> roleNames() const;
public:
    void updateMessage(const Message& data);

private:
    QHash<int, QByteArray> m_nameRoles;
    QList<Message*> mListMessage;
//    std::shared_ptr<Message> mMessagePtr;
};

#endif // MESSAGEMODEL_H
