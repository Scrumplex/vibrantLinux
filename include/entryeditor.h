#ifndef ENTRYEDITOR_H
#define ENTRYEDITOR_H

#include <vector>

#include <QDialog>
#include <QFileDialog>
#include <QListWidgetItem>
#include <QFile>
#include <QMessageBox>

#include "displaytab.h"
#include "programinfo.h"

namespace Ui {
	class entryEditor;
}

class entryEditor : public QDialog{
	Q_OBJECT

public:
	/*
	 * the user data for this should point to a programInfo struct.
	 * pass display names even though entry's info contains them. The reason for this is
	 * because we want to the names to show up in the same order everytime the program is run
	 * and that is not guaranteed when iterating over a QHash
	*/
	explicit entryEditor(programInfo& entry, const QStringList& displayNames, QWidget* parent = nullptr);
	~entryEditor();

private slots:
	void on_pathSelectBt_clicked();
	void on_titleMatchTypeCb_currentIndexChanged(int index);

	void on_pathMatchRbt_clicked();
	void on_titleMatchRbt_clicked();

private:
	void accept();

	Ui::entryEditor *ui;
	programInfo &entry;
};

#endif // ENTRYEDITOR_H
