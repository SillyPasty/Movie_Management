#pragma once
#ifndef SQLFUNS_H
#define SQLFUNS_H
#include <QString>
#include <QtSql>
#include <QMessageBox>
#include <algorithm>

extern QString global_userName;


class SqlFuns
{
public:

// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//
//																										  //
//                          ????????????????????????????							  // 
//																										  //
// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//

	bool connect(const QString& dbName);										//  ????????
	void createTables();														//  ??????

	
// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//
//																										  //
//                               ????????????????????????							  // 
//																										  //
// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//

	void registerUser(QString userId, QString password, QString name, \			//	?????
		QString sex, QString phonenumber, QString email, int isAdmin, \ 
		QString cinema);

	void addNewFilm(QString movieId, QString name, QString cinema, \			//	???????	
		QString hall, QString startTime, QString endTime, int length,\
		float price, int ticketRemain, QString type, int isRecommened, \
		QString date, QString seatMaps, QString language, int isDiscount);
	void addNewHall(QString hallId, QString cinema, int totalseats, \			//	?????	
		int row, int column, QString seatMap, QString type);
	void addNewHallTemplate();													//	???????
	QString addNewOrder(QString movieId, int seats1pos, int seats2pos, \		//	?????		
		int seat3pos, QString curTimeDate, float price);


// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//
//																										  //
//          ???????query?????????????????????????????????????         // 
//																										  //
// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//

	QString getHallId();
	//  ????
	QString queryPassword(QString userName); //
	int queryIsadmin(QString userName);      //  ??????????
	int queryHallSeates(QString hallId);
	QString queryCinema(QString userId);
	QString queryMovieName(QString movieId);
	QString querySeatMap(QString movieId);
	QSqlTableModel* queryAdminMovie(QString movieName, QString hallId);
	QSqlTableModel* queryAdminHall(QString hallId);
	QSqlTableModel* queryAdminOrder(QString movieName, QString userId, QString startDate, QString endDate, int isPlayed);
	QSqlTableModel* queryUserMovie(QString movieName, QString cinema, QString type, QString language);
	QSqlTableModel* queryUserOrder(QString movieName, QString cinema);
	//  ????
	int queryRow(QString hallId, QString cinema);
	int queryColumn(QString hallId, QString cinema);
	//  ????
	QStringList queryHallId(QString cinema);
	QStringList queryEmailPhonePsd(QString userId);
	QStringList queryType();
	QStringList queryCinema();
	QStringList queryOrderInfo(QString movieId);
	QStringList queryHallTemplateInfo();              //  ??????type??
	QStringList queryHallTemplateInfo(QString type);  //  ????type?????
	QStringList queryMovieInfo(QString movieId);
	int* querySeates(QString orderId);
	QString queryType(QString hallId, QString cinema);
	QString queryHallSeatMap(QString hallId);
	float queryPrice(QString movieId);
	float queryBalance();
	int addNewFilmJudge(QString hallId, QString start_time, QString end_time, QString film_date);
	int queryIsDiscount(QString movieId);
	void checkIsPlayed();


// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//
//																										  //
//          ?????????????????????????????????????????					  // 
//																										  //
// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//

	//  ????
	int cancelOrders(QString orderId);
	void delete_occupied_seats(QString orderId);
	void delete_outdated_orders(QString now_time, QString date);

	//  ????
	void changeUserInfo(QString email, QString passwd, QString phoneNum);
	float changeUserBalance(float amount);
	void changePaymentStage(QString orderId, int num, float price);
	void updateSeatMap(QString movieId, QString seatMap);

	
// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//
//																										  //
//												????					                                  // 
//																										  //
// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//


	int seatTrans(int row, int column, int curRow, int curColumn);
	//  ????
	int judgeSeatOrder(QString movieId, int seat1pos, int seat2pos, int seat3pos);
	int judgeUserOrderNumber(QString date);
	int warning_confilcted_orders(QString movieId);

	//	????
	int intelligentSeatsRecommend(QString movieId, int num);
	QString formal(QString str);												//  TEXT???
	int returnMinute(QString time_to_convert, QString date_to_convert);			//	???1970-01-01 00:00???????	
	SqlFuns();
};

#endif // SQLFUNS_H