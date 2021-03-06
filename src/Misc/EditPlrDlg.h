/****************************************************************************

	EditPlrDlg Class
	Copyright (C) 2009 Andre Deperrois adeperrois@xflr5.com

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

*****************************************************************************/
#ifndef EDITPLRDLG_H
#define EDITPLRDLG_H

#include <QDialog>
#include <QPushButton>
#include <QListWidget>
#include <QDoubleSpinBox>
#include <QLabel>

#include "../Objects/Polar.h"
#include "../Objects/WPolar.h"
#include "../Graph/Curve.h"


class EditPlrDlg : public QDialog
{
	Q_OBJECT

	friend class QXDirect;
	friend class QMiarex;

public:
	EditPlrDlg();
	void InitDialog();

private slots:
	void OnDeletePoint();
    //void OnDeleteAllPoints();

    void UpdateSpinBox1(int row);
    void ClChanged1(double val);
    void CdChanged1(double val);
    void CreateGraphs(int row);

private:
	void SetupLayout();
	void FillTable();
	void keyPressEvent(QKeyEvent *event);

private:
	QPushButton *m_pctrlDeletePoint, *m_pctrlDeleteAllPoints;
	QPushButton *OKButton, *CancelButton;

	QListWidget *m_pctrlAlphaList;
    QDoubleSpinBox *m_pctrlClBox, *m_pctrlCdBox;
	CPolar *m_pPolar;
    CWPolar *m_pWPolar;
    QLabel *m_pctrlClLabel, *m_pctrlCdLabel;


	void *m_pXDirect;
	void *m_pMiarex;

    int curIndex1;
};

#endif // EDITPLRDLG_H
