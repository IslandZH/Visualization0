#include "myjson.h"

myjson::myjson(QJsonObject jsonObject)
{
    QJsonArray results = jsonObject["results"].toArray();
    for(int i = 0; i < results.count(); i++)
    {
        QJsonObject galData(results.at(i).toObject());
        galgame* gal = new galgame();
        gal->id = galData["id"].toString();
        gal->languages = toStringArray(galData["languages"]);
        gal->length_minutes = galData["length_minutes"].toInt();
        gal->length_votes = galData["length_votes"].toInt();
        gal->platforms = toStringArray(galData["platforms"]);
        gal->rating = galData["rating"].toDouble();
        gal->title = galData["title"].toString();
        gal->votecount = galData["votecount"].toInt();
        galgames.append(gal);
    }
}

QVector<QString> myjson::toStringArray(QJsonValue jsonValue)
{
    QVector<QString> res;
    QJsonArray jsonArray = jsonValue.toArray();
    for(int i = 0; i < jsonArray.count(); i++)
    {
        QString string = jsonArray.at(i).toString();
        res.append(string);
    }
    return res;
}
