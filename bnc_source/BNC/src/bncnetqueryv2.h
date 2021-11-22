#ifndef BNCNETQUERYV2_H
#define BNCNETQUERYV2_H

#include "bncnetquery.h"

class bncNetQueryV2 : public bncNetQuery {
 Q_OBJECT

 public:
  bncNetQueryV2(bool secureServer, bool secureClient, int ntripVersion);
  virtual ~bncNetQueryV2();

  virtual void stop();
  virtual void waitForRequestResult(const QUrl& url, QByteArray& outData);
  virtual void startRequest(const QUrl& url, const QByteArray& gga);
  virtual void keepAliveRequest(const QUrl& url, const QByteArray& gga);
  virtual void waitForReadyRead(QByteArray& outData);

 private slots:
  void slotFinished();
  void slotProxyAuthenticationRequired(const QNetworkProxy&, QAuthenticator*);
  void slotSslErrors(QList<QSslError>);

 private:
  void startRequestPrivate(const QUrl& url, const QByteArray& gga, bool full);

  QNetworkAccessManager* _manager;
  QNetworkReply*         _reply;
  QEventLoop*            _eventLoop;
  bool                   _firstData;
  bool                   _secureServer;
  bool                   _secureClient;
  bool                   _sslIgnoreErrors;
  int                    _ntripVersion;
};

#endif
