/*
 * A tan input dialog for optical photoTan used in online banking
 * Copyright 2019  Jürgen Diez
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License or (at your option) version 3 or any later version
 * accepted by the membership of KDE e.V. (or its successor approved
 * by the membership of KDE e.V.), which shall act as a proxy
 * defined in Section 14 of version 3 of the license.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef PHOTOTANDIALOG_H
#define PHOTOTANDIALOG_H

#include <memory>

#include <QDialog>
#include <QGraphicsPixmapItem>

namespace Ui
{
class photoTanDialog;
}

class photoTanDialog : public QDialog
{
  Q_OBJECT
  Q_PROPERTY(QString infoText READ infoText() WRITE setInfoText)
  Q_PROPERTY(QPixmap picture READ picture() WRITE setPicture)

public:
  photoTanDialog(QWidget* parent = 0);
  ~photoTanDialog();

  enum Result { Accepted = 0, Rejected, InternalError };

  QString infoText();
  QString tan();
  QPixmap picture();

public slots:
  void accept();
  void reject();

  void setInfoText(const QString&);
  void setPicture(const QPixmap&);

  void setTanLimits(const int& minLength, const int& maxLength);

private slots:
  void tanInputChanged(const QString&);

private:
  Ui::photoTanDialog* ui;
  QGraphicsPixmapItem *pictureItem;
  QString m_tan;
  bool m_accepted;
};

#endif // PHOTOTANDIALOG_H
