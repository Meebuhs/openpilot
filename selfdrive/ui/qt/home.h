#pragma once

#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QStackedLayout>
#include <QTimer>
#include <QWidget>

#include "selfdrive/ui/qt/offroad/driverview.h"
#include "selfdrive/ui/qt/onroad.h"
#include "selfdrive/ui/qt/sidebar.h"
#include "selfdrive/ui/qt/widgets/offroad_alerts.h"
#include "selfdrive/ui/ui.h"

class OffroadHome : public QFrame {
  Q_OBJECT

public:
  explicit OffroadHome(QWidget* parent = 0);

private:
  void showEvent(QShowEvent *event) override;
  void hideEvent(QHideEvent *event) override;
  void mouseReleaseEvent(QMouseEvent *event) override;
  void paintEvent(QPaintEvent *event) override;
  void refresh();
  const QRect poweroff_btn = QRect(50, 35, 200, 117);

  QImage poweroff_img;
  QTimer* timer;
  QLabel* date;
  QLabel* version;
  QStackedLayout* center_layout;
  UpdateAlert *update_widget;
  OffroadAlert* alerts_widget;
  QPushButton* alert_notif;
  QPushButton* update_notif;
};

class HomeWindow : public QWidget {
  Q_OBJECT

public:
  explicit HomeWindow(QWidget* parent = 0);

signals:
  void openSettings();
  void closeSettings();

  // forwarded signals
  void displayPowerChanged(bool on);
  void update(const UIState &s);
  void offroadTransitionSignal(bool offroad);

public slots:
  void offroadTransition(bool offroad);
  void showDriverView(bool show);
  void showSidebar(bool show);

protected:
  void mousePressEvent(QMouseEvent* e) override;

private:
  Sidebar *sidebar;
  OffroadHome *home;
  OnroadWindow *onroad;
  DriverViewWindow *driver_view;
  QStackedLayout *slayout;
};
