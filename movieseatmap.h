#ifndef MOVIESEATMAP_H
#define MOVIESEATMAP_H

#include <QWidget>
#include "sqlfuns.h"

namespace Ui {
class MovieSeatMap;
}

class MovieSeatMap : public QWidget
{
    Q_OBJECT

public:
    explicit MovieSeatMap(QWidget *parent = nullptr);
    void showSeat(QString seatMap);
    ~MovieSeatMap();

private:
    Ui::MovieSeatMap *ui;

private slots:
    void receiveMovieDetail(QString movieId);
};

#endif // MOVIESEATMAP_H
