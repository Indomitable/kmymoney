/***************************************************************************
                             kaccounttypepage.h
                             -------------------
    begin                : Tue Sep 25 2007
    copyright            : (C) 2007 Thomas Baumgart
    email                : Thomas Baumgart <ipwizard@users.sourceforge.net>
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef KNEWACCOUNTWIZARDACCOUNTTYPEPAGE_H
#define KNEWACCOUNTWIZARDACCOUNTTYPEPAGE_H

// ----------------------------------------------------------------------------
// QT Includes

#include <QWidget>

// ----------------------------------------------------------------------------
// KDE Includes

// ----------------------------------------------------------------------------
// Project Includes

#include "wizardpage.h"

class MyMoneyAccount;
class MyMoneySecurity;

namespace eMyMoney { enum class Account; }

namespace NewAccountWizard
{
  class Wizard;

  class AccountTypePagePrivate;
  class AccountTypePage : public QWidget, public WizardPage<Wizard>
  {
    Q_OBJECT
    Q_DISABLE_COPY(AccountTypePage)

  public:
    explicit AccountTypePage(Wizard* parent);
    ~AccountTypePage() override;

    virtual bool isComplete() const;
    KMyMoneyWizardPage* nextPage() const;

    QWidget* initialFocusWidget() const override;

    eMyMoney::Account accountType() const;
    const MyMoneyAccount& parentAccount();
    bool allowsParentAccount() const;
    const MyMoneySecurity& currency() const;

    void setAccount(const MyMoneyAccount& acc);

  private:
    void hideShowPages(eMyMoney::Account i) const;
    void priceWarning(bool);

  private slots:
    void slotUpdateType(int i);
    void slotUpdateCurrency();
    void slotUpdateConversionRate(const QString&);
    void slotGetOnlineQuote();
    void slotPriceWarning();

  private:
    Q_DECLARE_PRIVATE_D(WizardPage<Wizard>::d_ptr, AccountTypePage)
    friend class Wizard;
    friend class AccountSummaryPage;
    friend class BrokeragePage;
    friend class CreditCardSchedulePage;
    friend class LoanPayoutPage;
  };
} // namespace

#endif
